# $NetBSD: Makefile,v 1.1.1.1 2003/09/30 13:41:34 xtraeme Exp $
#

DISTNAME=	adtool-1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://c128.org/adtool/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://c128.org/adtool/
COMMENT=	Active Directory administration utility for Unix

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

EGDIR=			${PREFIX}/share/examples/adtool
CONF_FILES=		${EGDIR}/adtool.cfg.dist ${PKG_SYSCONFDIR}/adtool.cfg

.include "../../databases/openldap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
