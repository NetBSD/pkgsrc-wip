# $NetBSD: Makefile,v 1.2 2003/09/17 17:47:09 xtraeme Exp $
#

DISTNAME=		thy-0.5.2
CATEGORIES=		www
MASTER_SITES=		ftp://bonehunter.rulez.org/pub/thy/stable/

MAINTAINER=		algernon@bonehunter.rulez.org
HOMEPAGE=		http://bonehunter.rulez.org/Thy.phtml
COMMENT=		Tiny and fast HTTP daemon

BUILD_DEFS+=		USE_INET6
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes

PKG_SYSCONFSUBDIR=	thy
CONF_FILES=		${EGDIR}/thy.conf ${PKG_SYSCONFDIR}/thy.conf \
			${EGDIR}/http301.html ${PKG_SYSCONFDIR}/http301.html \
			${EGDIR}/http302.html ${PKG_SYSCONFDIR}/http302.html \
			${EGDIR}/http400.html ${PKG_SYSCONFDIR}/http400.html \
			${EGDIR}/http401.html ${PKG_SYSCONFDIR}/http401.html \
			${EGDIR}/http403.html ${PKG_SYSCONFDIR}/http403.html \
			${EGDIR}/http404.html ${PKG_SYSCONFDIR}/http404.html \
			${EGDIR}/http405.html ${PKG_SYSCONFDIR}/http405.html \
			${EGDIR}/http412.html ${PKG_SYSCONFDIR}/http412.html \
			${EGDIR}/http416.html ${PKG_SYSCONFDIR}/http416.html \
			${EGDIR}/http500.html ${PKG_SYSCONFDIR}/http500.html \
			${EGDIR}/http501.html ${PKG_SYSCONFDIR}/http501.html \
			${EGDIR}/http505.html ${PKG_SYSCONFDIR}/http505.html
RCD_SCRIPTS=		thy
INFO_FILES=		thy.info

CONFIGURE_ENV+=		CFLAGS=-Wno-shadow
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

EGDIR=			${PREFIX}/share/thy/samples

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET} \
		pkgconfdir=${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/thy.conf ${EGDIR}/

.include "../../security/gnutls/buildlink2.mk"
.include "../../security/PAM/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
