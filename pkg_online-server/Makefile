# $NetBSD: Makefile,v 1.3 2010/01/09 12:04:24 cheusov Exp $
#

PKGNAME=	${DISTNAME:C/online/online-server/}
CATEGORIES=	pkgtools
COMMENT+=	(server tools)

DEPENDS+=	dict-server>=1.10.10nb2:../../textproc/dict-server
DEPENDS+=	pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus

INSTALL_TARGET=	install-server

AUTO_MKDIRS=	yes

DESCR_SRC+=	${.CURDIR}/DESCR

MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/pkg_online-server

.include "../../wip/pkg_online-server/Makefile.common"
.include "../../mk/bsd.pkg.mk"
