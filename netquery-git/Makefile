# $NetBSD: Makefile.common,v 1.7 2015/07/20 05:49:53 adam Exp $

PKGNAME=	netquery-0
CATEGORIES=	sysutils

GIT_REPOSITORIES=	netquery
GIT_REPO.netquery=	https://github.com/krytarowski/netquery.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#
COMMENT=	System introspection tool
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_TOOLS=	automake autoconf autoreconf

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../wip/mk/git-package.mk"
.include "../../wip/libgraphqlparser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
