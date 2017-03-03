#define NALLOC 1024 // min units to request

typedef long Align; // for alignment to long boundary

union header {
  struct {
    union header *next_p; // next block if on free list
    unsigned size; // size of block
  } s;
  Align x; // force alignment of blocks
};

typedef union header Header;

static Header base; // empty list to start with
static Header *free_p = NULL; // start of free list

void* m_alloc(unsigned n_bytyes);
void free(void* ap);
static Header* more_core(unsigned nu);

void* m_alloc(unsigned n_bytyes)
{
  Header* p;
  Header* prev_p;
  Header* more_core(unsigned);
  unsigned n_units;

  n_units = (n_bytyes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prev_p = free_p) == NULL) { // no free list yet
    base.s.next_p = free_p = prev_p = &base;
    base.s.size = 0;
  }

  for (p = prev_p->s.next_p; ; prev_p = p, p = p->s.next_p) {
    if (p->s.size >= n_units) { // big enough
      if (p->s.size == n_units) { // exact match
        prev_p->s.next_p = p->s.next_p;
      } else {
        // allocate tail end
        p->s.size -= n_units;
        p += p->s.size;
        p->s.size = n_units;
      }
      free_p = prev_p;

      return (void*) (p + 1);
    }

    if (p == free_p) { // wrapped around free list
      if ((p = more_core(n_units)) == NULL) {
        return NULL;
      }
    }
  }
}

static Header* more_core(unsigned nu)
{
  char* cp;
  char* sbrk(int);
  Header* up;

  if (nu < NALLOC)
    nu = NALLOC;

   cp = sbrk(nu * sizeof(Header));
   if (cp == (char*) -1) // no space left
    return NULL;

   up = (Header*) cp;
   up->s.size = nu;
   free((void*)(up + 1));

   return free_p;
}

void free(void* ap)
{
  Header* bp;
  Header* p;

  bp = (Header*) ap - 1; // point to block header
  for (p = free_p; !(bp > p && bp < p->s.next_p); p = p->s.next_p)
    if (p >= p->s.next_p && (bp > p || bp < p->s.next_p))
      break; // freed block at start or end

  if (bp + bp->s.size == p->s.next_p) { // join to upper nbr
    bp->s.size += p->s.next_p->s.size;
    bp->s.next_p = p->s.next_p->s.next_p;
  } else
    bp->s.next_p = p->s.next_p;

  if (p + p->s.size == bp) { // join to lower nbr
    p->s.size += bp->s.size;
    p->s.next_p = bp->s.next_p;
  } else
    p->s.next_p = bp;

  free_p = p;
}
