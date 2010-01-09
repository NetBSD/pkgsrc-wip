# $NetBSD: Makefile,v 1.4 2010/01/09 12:11:24 cheusov Exp $
#

.include "../../wip/pkg_online-server/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-client/}
CATEGORIES=	pkgtools
COMMENT+=	(client tools)

DEPENDS+=	dict-client>=1.10.9:../../textproc/dict-client
DEPENDS+=	pkg_summary-utils-[0-9]*:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../wip/pipestatus
DEPENDS+=	netcat-[0-9]*:../../net/netcat

INSTALL_TARGET=	install-client

AUTO_MKDIRS=	yes

DESCR_SRC+=	${.CURDIR}/DESCR

MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/pkg_online-client

.include "../../mk/bsd.pkg.mk"
