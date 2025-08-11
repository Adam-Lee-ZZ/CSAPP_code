# Note of Chapter 3: Machine-Level Reprecentation of Programs

## 3.4.3 Data Movement Example

In this section, an example is offered like below:

```C
long exchange(long *xp, long y){
    long x = *xp;
    *xp = y;
    return x;
}
```

In this function, anthough *xp is changed by the line "*xp = y", 
the value of x will not be changed though. (Which means the function will 
return the original *xp value.) This feature of the C may be confused for
those who used to program in python and are new to C. However, the 
assembly code offers us a great view of the logic behind it.

```
exchange:
    movq    (%rdi), %rax
    movq    %rsi, (%rdi)
    ret
```

After excute the intstruction "long x = *xp", which correspond to the 
assembly code "movq    (%rdi), %rax", the adress stored in %rdi is used to
locate the position in the memory. The value stored in the memory is copied
and stored in the register %rax. After doing this, the value stored in %rdi,
which correspod to y, is copied and stored in the original position in the 
memory. However, in this progress, %rax is not changed.

![Progress](Image\Fig3_1.jpg "Value-unchange progress")