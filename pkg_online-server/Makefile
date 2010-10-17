# $NetBSD: Makefile,v 1.6 2010/10/17 14:49:04 cheusov Exp $
#

.include "../../wip/pkg_online-server/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-server/}
CATEGORIES=	pkgtools
COMMENT+=	(server tools)

DEPENDS+=	dict-server>=1.10.10nb2:../../textproc/dict-server
DEPENDS+=	pkg_summary-utils>=0.18.1:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus

BUILD_DEPENDS+=	mk-configure>=0.20.0:../../wip/mk-configure

INSTALL_TARGET=	install-server install-doc

DESCR_SRC+=	${.CURDIR}/DESCR

DOCDIR=		${PREFIX}/share/doc/pkg_online-server
EGDIR=		${PREFIX}/share/examples/pkg_online-server

MAKE_ENV+=	DOCDIR=${DOCDIR} EGDIR=${EGDIR}

CONF_FILES=     ${EGDIR}/pkg_online_server.conf \
                ${PKG_SYSCONFDIR}/pkg_online_server.conf

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	mkcmake
