# $NetBSD: Makefile,v 1.1.1.1 2012/03/06 09:58:51 ftigeot Exp $

VER=		1.2.2
DISTNAME=	mythes-${VER}
PKGNAME=	libmythes-${VER:S/-//g}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hunspell}/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://hunspell.sourceforge.net/
COMMENT=	Library and tools for parsing the visio file format
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

REPLACE_PERL=	th_gen_idx.pl

.include "../../textproc/hunspell/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
