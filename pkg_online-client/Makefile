# $NetBSD: Makefile,v 1.8 2011/01/20 23:28:06 cheusov Exp $
#

.include "../../wip/pkg_online-server/Makefile.common"

PKGNAME=	${DISTNAME:C/online/online-client/}
CATEGORIES=	pkgtools
COMMENT+=	(client tools)

DEPENDS+=	dict-client>=1.10.9:../../textproc/dict-client
DEPENDS+=	pkg_summary-utils>=0.49:../../wip/pkg_summary-utils
DEPENDS+=	pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=	netcat-[0-9]*:../../net/netcat

BUILD_DEPENDS+=	mk-configure>=0.20.0:../../devel/mk-configure

INSTALL_TARGET=	install-client install-doc

DESCR_SRC+=	${.CURDIR}/DESCR

DOCDIR=		${PREFIX}/share/doc/pkg_online-client
EGDIR=		${PREFIX}/share/examples/pkg_online-client

MAKE_ENV+=	DOCDIR=${DOCDIR} EGDIR=${EGDIR}

CONF_FILES=     ${EGDIR}/pkg_online_client.conf \
                ${PKG_SYSCONFDIR}/pkg_online_client.conf

.include "../../mk/bsd.pkg.mk"

MAKE_PROGRAM=	mkcmake
