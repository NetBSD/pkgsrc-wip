# $NetBSD: Makefile,v 1.2 2012/09/29 17:05:56 asau Exp $
#

DISTNAME=		1.1.2
PKGNAME=		hgsubversion-${DISTNAME}
EGG_NAME=		hgsubversion-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://bitbucket.org/durin42/hgsubversion/get/

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://bibucket.org/durin42/hgsubversion/
COMMENT=		Subversion plugin for Mercurial
LICENSE=		gnu-gpl-v2

DIST_SUBDIR=    hgsubversion
WRKSRC=		${WRKDIR}/hgsubversion

DEPENDS+=	mercurial>=1.3.1:../../devel/mercurial
DEPENDS+=	subversion-base>=1.5:../../devel/subversion-base

pre-build:
	${ECHO} "tag: ${DISTNAME}" >> ${WRKSRC}/.hg_archival.txt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
