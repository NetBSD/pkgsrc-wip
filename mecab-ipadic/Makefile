# $NetBSD: Makefile,v 1.1.1.1 2006/03/19 14:03:07 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-ipadic-2.7.0-20051110
PKGNAME=	mecab-ipadic-2.7.0.20051110
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/18371/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	Japanese Morphological Dictionary for MeCab

DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../wip/mecab-base

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
