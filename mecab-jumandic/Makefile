# $NetBSD: Makefile,v 1.1.1.1 2006/03/19 13:50:25 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-5.1-20051121
PKGNAME=	mecab-jumandic-5.1.20051121
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/18372/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	Japanese Morphological Dictionary for MeCab

DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../wip/mecab-base

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
