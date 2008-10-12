# $NetBSD: Makefile,v 1.1.1.1 2008/10/12 10:44:07 cheusov Exp $
#

.include "../../wip/pkg_online/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-server/}
CATEGORIES=	pkgtools
COMMENT+=	(server tools)

DEPENDS+=	dict-server>=1.10.10nb2:../../wip/dict-server
DEPENDS+=	pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus

INSTALL_TARGET=	install-server

AUTO_MKDIRS=	yes

DESCR_SRC+=	${.CURDIR}/DESCR

MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/pkg_online-server

.include "../../mk/bsd.pkg.mk"
