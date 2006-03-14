# $NetBSD: Makefile,v 1.8 2006/03/14 01:28:13 jlamwww Exp $

DISTNAME=	siproxd-0.5.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=siproxd/}

MAINTAINER=     schwarz@NetBSD.org
HOMEPAGE=	http://siproxd.sourceforge.net/
COMMENT=	Session Initiation Protocol Application-Level Gateway (SIP ALG)

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-libosip-prefix=${BUILDLINK_PREFIX.libosip2}
EGDIR=		${PREFIX}/share/examples/siproxd

CONF_FILES=	${EGDIR}/siproxd.conf.example ${PKG_SYSCONFDIR}/siproxd.conf \
		${EGDIR}/siproxd_passwd.cfg \
		${PKG_SYSCONFDIR}/siproxd_passwd.cfg

INSTALLATION_DIRS=	sbin share/examples/siproxd

.include "../../devel/libosip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
