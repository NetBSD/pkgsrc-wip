# $NetBSD: Makefile,v 1.3 2012/10/07 20:02:40 asau Exp $
#

DISTNAME=	yersinia-0.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.yersinia.net/download/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://www.yersinia.net/
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--disable-gtk #for now
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=	LIBNET_CONFIG=${LIBNET_CONFIG}

LIBNET_CONFIG?=	${PREFIX}/bin/libnet11-config

SUBST_CLASSES+=		script
SUBST_STAGE.script=	post-patch
SUBST_SED.script=	-e 's|-lnet|`${LIBNET_CONFIG} --libs`|'
SUBST_FILES.script=	src/Makefile.in
USE_NCURSES=		yes#

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${DESTDIR}${PREFIX}/bin/yersinia
	${INSTALL_MAN}	${WRKSRC}/yersinia.8	${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/libnet11/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
