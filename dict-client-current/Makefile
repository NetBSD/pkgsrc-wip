# $NetBSD: Makefile,v 1.21 2015/03/01 14:59:36 cheusov Exp $

PKGNAME=	dict-client-2.0.0
CATEGORIES=	textproc

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/dictd
COMMENT=	Dictionary Service Protocol client
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	dictd
GIT_REPO.dictd=		https://github.com/cheusov/dictd.git

WRKSRC=			${WRKDIR}/dictd
EGDIR=			${PREFIX}/share/examples/dict

CONF_FILES=		${EGDIR}/dict.conf \
			${PKG_SYSCONFDIR}/dict.conf
TOOL_DEPENDS+=		mk-configure>=0.38.2:../../devel/mk-configure

CONFIGURE_TARGET=	configure-dict
BUILD_TARGET=		all-dict
INSTALL_TARGET=		install-dict

#CONF_FILES=		dict.conf   ${PKG_SYSCONFDIR}/dict.conf

.include "../../devel/mk-configure/mk-c.mk"
.include "../../devel/libmaa/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
