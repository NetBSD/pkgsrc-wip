# $NetBSD: Makefile,v 1.2 2014/09/18 05:16:17 makoto Exp $

PKGNAME=	gnuradio-utils-${VERSION}
COMMENT=	Utilities in GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

CONF_FILES+=	${EGDIR}/modtool.conf	${PKG_SYSCONFSUBDIR}/modtool.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_UTILS=True

.include        "../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
