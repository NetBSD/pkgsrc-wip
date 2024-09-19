$NetBSD$

9a10,12
> /*****
> TL: I'd rename everything referencing "euro" to "currency" instead.
> *****/
26a30,32
> /*****
> TL: this is from Unicode character category Sc
> *****/
28c34,55
< 	0X20AC,
---
> 	0x0024,
>         START_RANGE_PAIR,
> 	0x00A2,0x00A5,
> 	0x058F,
> 	0x060B,
> 	0x09F2,
> 	0x09F3,
> 	0x09FB,
> 	0x0AF1,
> 	0x0BF9,
> 	0x0E3F,
> 	0x17DB,
>         START_RANGE_PAIR,
> 	0x20A0,0x20BD,
> 	0xA838,
> 	0xFDFC,
> 	0xFE69,
> 	0xFF04,
> 	0xFFE0,
> 	0xFFE1,
> 	0xFFE5,
> 	0xFFE6,
45,46c72,73
< 	"Euro",
< 	"Euro",
---
> 	"Currency",
> 	"Currency",
