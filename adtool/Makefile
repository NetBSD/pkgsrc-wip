# $NetBSD: Makefile,v 1.3 2004/04/25 07:01:05 blef Exp $
#

DISTNAME=	adtool-1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://c128.org/adtool/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://c128.org/adtool/
COMMENT=	Active Directory administration utility for Unix

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/adtool
CONF_FILES=		${EGDIR}/adtool.cfg.dist ${PKG_SYSCONFDIR}/adtool.cfg

.include "../../databases/openldap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
