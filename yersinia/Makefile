# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 15:14:38 prudhvikrishna Exp $
#

DISTNAME=	yersinia-0.7.1
CATEGORIES=	security
MASTER_SITES=	http://www.yersinia.net/download/

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://www.yersinia.net/
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

PKG_DESTDIR_SUPPORT+=	user-destdir

CONFIGURE_ARGS+=	--disable-gtk #for now
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	LIBNET_CONFIG=${LIBNET_CONFIG}

LIBNET_CONFIG?=	${PREFIX}/bin/libnet11-config

SUBST_CLASSES+=	script
SUBST_STAGE.script=	post-patch
SUBST_SED.script=	-e 's|-lnet|`${LIBNET_CONFIG} --libs`|'
SUBST_FILES.script=	src/Makefile.in
USE_NCURSES=	yes#

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${PREFIX}/bin/yersinia
	${INSTALL_MAN}	${WRKSRC}/yersinia.8	${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/libnet11/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
