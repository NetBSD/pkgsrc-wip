# $NetBSD: Makefile,v 1.3 2006/08/11 08:49:11 ghen Exp $

.include "../../wip/pdns2/Makefile.common"

PKGNAME=		${DISTNAME:S/pdns/pdns-gmysql/}
COMMENT=		MySQL backend plugin for PowerDNS
DEPENDS+=		${DISTNAME}:../../wip/pdns2

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/pdns
CONFIGURE_ARGS+=	--with-dynmodules="gmysql"
CONFIGURE_ARGS+=	--with-modules=""
CONFIGURE_ARGS+=	--disable-pdns_server
CONFIGURE_ARGS+=	--disable-recursor
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql

# dirty hack to avoid build man pages
post-patch:
	${SED} -e "s|^install-man: install-man8|install-man:|" \
	< ${WRKSRC}/Makefile.in > ${WRKSRC}/Makefile.in.tmp
	${MV} ${WRKSRC}/Makefile.in.tmp ${WRKSRC}/Makefile.in

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
