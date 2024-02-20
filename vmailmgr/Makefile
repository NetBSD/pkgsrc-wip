# $NetBSD$

DISTNAME=		vmailmgr-0.97-1.src.rpm
PKGNAME=		${DISTNAME:S/-1.src.rpm$//}
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}current/
EXTRACT_SUFX=		# none
EXTRACT_CMD=		${TAR} xzf $${extract_file} && ${TAR} xzf ${PKGNAME_NOREV}.tar.gz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/vmailmgr/
COMMENT=		Manage multiple mail domains on a single qmail host
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf213 automake14 gmake perl tar
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mk/bsd.pkg.mk"
