# $NetBSD: Makefile,v 1.1 2013/11/03 21:42:26 ishit Exp $

DISTNAME=	marisa-0.2.4
CATEGORIES=	textproc
MASTER_SITES=	http://marisa-trie.googlecode.com/files/

MAINTAINER=	ishit@users.sourceforge.net
HOMEPAGE=	http://code.google.com/p/marisa-trie/
COMMENT=	Matching Algorithm with Recursively Implemented StorAge
LICENSE=	modified-bsd gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=	c c++

#TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	marisa.pc.in

.include "../../mk/bsd.pkg.mk"
