# $NetBSD: Makefile,v 1.2 2006/08/11 07:57:42 ghen Exp $

.include "Makefile.common"

COMMENT=		Modern, advanced and high performance nameserver

CONFIGURE_ARGS+=	--with-modules="" --with-dynmodules=""
RCD_SCRIPTS=		pdns
#LDFLAGS+=		-lrt

EGDIR=			${PREFIX}/share/examples/pdns
MAKE_ENV+=		EGDIR=${EGDIR}

CONF_FILES+=		${EGDIR}/pdns.conf-dist ${PKG_SYSCONFDIR}/pdns.conf

.include "../../mk/bsd.pkg.mk"
