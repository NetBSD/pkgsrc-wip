# $NetBSD: Makefile,v 1.5 2010/03/13 17:50:09 cheusov Exp $
#

.include "../../wip/pkg_online-server/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-server/}
CATEGORIES=	pkgtools
COMMENT+=	(server tools)

DEPENDS+=	dict-server>=1.10.10nb2:../../textproc/dict-server
DEPENDS+=	pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus

INSTALL_TARGET=	install-server

AUTO_MKDIRS=	yes

DESCR_SRC+=	${.CURDIR}/DESCR

MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/pkg_online-server

.include "../../mk/bsd.pkg.mk"
