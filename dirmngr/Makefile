# $NetBSD: Makefile,v 1.2 2004/10/15 22:23:27 johnrshannon Exp $
#

DISTNAME=		dirmngr-0.5.6
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/alpha/dirmngr/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		http://www.gnupg.org/aegypten2
COMMENT=		X509 certificate and CRL downloader

BUILD_USES_MSGFMT=	yes

INFO_FILES=		dirmngr.info
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=         make
USE_GNU_TOOLS+=		awk
AUTOCONF_REQD=		2.52
CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
#CONFIGURE_ARGS+=	--disable-nls
# gettext Version 0.12.1 or newer is required
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

pre-configure:
#			cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} autogen.sh
			cd ${WRKSRC} && ${AUTOCONF}

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../wip/libassuan/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../wip/gettext-lib/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
