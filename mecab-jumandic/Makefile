# $NetBSD: Makefile,v 1.4 2007/04/01 02:19:13 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20070304
PKGNAME=	mecab-jumandic-5.1.20070304
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mecab/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mecab.sourceforge.net/
COMMENT=	Japanese Morphological Dictionary for MeCab

DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../wip/mecab-base

GNU_CONFIGURE=	yes

UNLIMIT_RESOURCES=	datasize

.include "../../mk/bsd.pkg.mk"
