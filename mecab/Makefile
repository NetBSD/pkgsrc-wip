# $NetBSD: Makefile,v 1.2 2007/03/12 14:10:28 obache Exp $

.include "Makefile.common"

DISTNAME=	mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	#empty
DISTFILES=	#empty

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.net/
COMMENT=	Yet Another Part-of-Speech and Morphological Analyzer

DEPENDS+=	mecab-base>=${MECAB_VERSION}:../../wip/mecab-base
DEPENDS+=	{mecab-ipadic>=2.7.0,mecab-jumandic>=5.1}:../../wip/mecab-ipadic

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	#empty

.include "../../mk/bsd.pkg.mk"
