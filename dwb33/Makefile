# $NetBSD: Makefile,v 1.1 2015/05/18 11:14:47 n-t-roff Exp $

V=		20150517
DISTNAME=	DWB3.3-${V}
CATEGORIES=	textproc
#MASTER_SITES=	https://github.com/n-t-roff/DWB3.3/releases/download/${V}/
MASTER_SITES=	${MASTER_SITE_GITHUB:=n-t-roff/DWB3.3/releases/download/${V}/}

MAINTAINER=	carsten.kunze@arcor.de
HOMEPAGE=	https://github.com/n-t-roff/DWB3.3
COMMENT=	"Original Documenter's Workbench Release 3.3"
LICENSE=	epl-v1.0

MAKE_FILE=	dwb.mk
USE_LANGUAGES=	c c++
USE_TOOLS+=	lex yacc
MAKE_JOBS_SAFE=	no

MAKE_FLAGS=	ROOT=${DESTDIR} \
		BINDIR=${PREFIX}/dwb33/bin \
		FONTDIR=${PREFIX}/dwb33/lib/font \
		HOSTDIR=${PREFIX}/dwb33/lib/font/postscript \
		LIBDIR=${PREFIX}/dwb33/lib/dwb \
		MACRODIR=${PREFIX}/dwb33/lib/macros \
		MAN1DIR=${PREFIX}/dwb33/man/man1 \
		MAN5DIR=${PREFIX}/dwb33/man/man5 \
		NTERMDIR=${PREFIX}/dwb33/lib/nterm \
		POSTBIN=${PREFIX}/dwb33/lbin/postscript \
		POSTLIB=${PREFIX}/dwb33/lib/postscript \
		PUBDIR=${PREFIX}/dwb33/pub \
		RASTDIR=${PREFIX}/dwb33/lib/raster \
		TMACDIR=${PREFIX}/dwb33/lib/tmac

.include "../../mk/bsd.pkg.mk"
