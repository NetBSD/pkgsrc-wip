# $NetBSD: Makefile,v 1.3 2015/05/19 10:55:31 n-t-roff Exp $

V=		20150517
DISTNAME=	DWB3.3-${V}
PKGNAME=	dwb33-${V}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=n-t-roff/DWB3.3/releases/download/${V}/}

MAINTAINER=	carsten.kunze@arcor.de
HOMEPAGE=	https://github.com/n-t-roff/DWB3.3
COMMENT=	"Original Documenter's Workbench Release 3.3"
LICENSE=	epl-v1.0

MAKE_FILE=	dwb.mk
USE_LANGUAGES=	c c++
USE_TOOLS+=	lex yacc
MAKE_JOBS_SAFE=	no

MAKE_FLAGS=	CFLGS="${CFLAGS}" \
		LDFLGS="${LDFLAGS}" \
		ROOT=${PREFIX}/dwb33

.include "../../mk/bsd.pkg.mk"
