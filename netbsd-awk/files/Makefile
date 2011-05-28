#	$NetBSD: Makefile,v 1.2 2011/05/28 16:20:07 cheusov Exp $

PROG=	nbawk
SRCS=	awkgram.y b.c lex.c lib.c main.c parse.c proctab.c run.c tran.c

MAN=	nbawk.1

YHEADER=	yes

MKC_COMMON_DEFINES.Linux=	-D_GNU_SOURCE
MKC_COMMON_HEADERS=		ctype.h stdio.h string.h

MKC_CHECK_FUNCS1=		__fpurge:stdio_ext.h fpurge isblank
MKC_CHECK_FUNCS3=		strlcat

MKC_SOURCE_FUNCLIBS=		fpurge strlcat

PROJECTNAME=	nbawk
VERSION=	20110509

MKC_REQD=	0.19.0

.include <mkc.configure.mk>

.if ${HAVE_FUNC1.isblank:U0}
CPPFLAGS+=	-DHAS_ISBLANK
.endif

.if !${HAVE_FUNC1.fpurge:U1} && !${HAVE_FUNC1.__fpurge.stdio_ext_h:U1}
MKC_ERR_MSG+=	"fpurge(3) cannot be found"
.endif

CPPFLAGS+=	-I. -DHAVE_NBTOOL_CONFIG_H=1
LDADD+=		-lm

WARNS=		4

.include <mkc.prog.mk>
