# $NetBSD: Makefile,v 1.7 2004/03/21 16:17:35 algernon Exp $
# arch-tag: 99a9d5e6-7144-4c79-b540-f70a2b55611b

DISTNAME=		thy-0.8.10
CATEGORIES=		www
MASTER_SITES=		ftp://bonehunter.rulez.org/pub/thy/devel/

MAINTAINER=		algernon@bonehunter.rulez.org
HOMEPAGE=		http://bonehunter.rulez.org/Thy.phtml
COMMENT=		Tiny and fast HTTP daemon

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
BUILD_DEFS+=		USE_INET6
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	thy
CONF_FILES=		${EGDIR}/thyrc ${PKG_SYSCONFDIR}/thyrc \
			${EGDIR}/http301.html ${PKG_SYSCONFDIR}/http301.html \
			${EGDIR}/http302.html ${PKG_SYSCONFDIR}/http302.html \
			${EGDIR}/http400.html ${PKG_SYSCONFDIR}/http400.html \
			${EGDIR}/http401.html ${PKG_SYSCONFDIR}/http401.html \
			${EGDIR}/http403.html ${PKG_SYSCONFDIR}/http403.html \
			${EGDIR}/http404.html ${PKG_SYSCONFDIR}/http404.html \
			${EGDIR}/http405.html ${PKG_SYSCONFDIR}/http405.html \
			${EGDIR}/http411.html ${PKG_SYSCONFDIR}/http411.html \
			${EGDIR}/http412.html ${PKG_SYSCONFDIR}/http412.html \
			${EGDIR}/http413.html ${PKG_SYSCONFDIR}/http413.html \
			${EGDIR}/http416.html ${PKG_SYSCONFDIR}/http416.html \
			${EGDIR}/http417.html ${PKG_SYSCONFDIR}/http417.html \
			${EGDIR}/http500.html ${PKG_SYSCONFDIR}/http500.html \
			${EGDIR}/http501.html ${PKG_SYSCONFDIR}/http501.html \
			${EGDIR}/http503.html ${PKG_SYSCONFDIR}/http503.html \
			${EGDIR}/http505.html ${PKG_SYSCONFDIR}/http505.html
RCD_SCRIPTS=		thy
INFO_FILES=		thy.info

CONFIGURE_ENV+=		CFLAGS=-Wno-shadow
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
MAKE_FLAGS+=		pkgconfdir=${EGDIR}

EGDIR=			${PREFIX}/share/thy/samples

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/thyrc ${EGDIR}/

.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
