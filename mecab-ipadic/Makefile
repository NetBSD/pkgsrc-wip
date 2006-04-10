# $NetBSD: Makefile,v 1.2 2006/04/10 01:22:09 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-ipadic-2.7.0-20060408
PKGNAME=	mecab-ipadic-2.7.0.20060408
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/19691/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	Japanese Morphological Dictionary for MeCab

DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../wip/mecab-base

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
