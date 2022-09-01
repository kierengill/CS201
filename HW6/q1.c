char *p1, *p2, *p3;
p1 = alloc(10);
p2 = alloc(20);
p3 = alloc(15);
afree(p3);
afree(p1);
afree(p2);

/* afree(p2) should be called before afree(p1) */
/* this is because an assumption is made that calls to alloc()/afree() are executed in a stack-like manner */