static __inline void
outb(unsigned char value, unsigned short port)
{
  __asm__ __volatile__ ("outb %b0,%w1": :"a" (value), "Nd" (port));
}

static __inline unsigned char
inb(unsigned short port)
{
  unsigned char _v;
  __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

static __inline void
outw(unsigned short value, unsigned short port)
{
  __asm__ __volatile__ ("outw %w0,%w1": :"a" (value), "Nd" (port));
}

static __inline unsigned short
inw(unsigned short port)
{
  unsigned short _v;
  __asm__ __volatile__ ("inw %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

static __inline void
outl(unsigned int value, unsigned short port)
{
  __asm__ __volatile__ ("outl %0,%w1": :"a" (value), "Nd" (port));
}

static __inline unsigned int
inl(unsigned short port)
{
  unsigned int _v;
  __asm__ __volatile__ ("inl %1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

