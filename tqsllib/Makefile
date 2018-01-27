# $NetBSD: Makefile,v 1.9 2012/12/29 12:20:54 thomasklausner Exp $

DISTNAME=	tqsllib-2_2
PKGNAME=	${DISTNAME:S/_/./}
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	http://www.arrl.org/files/file/LoTW%20Instructions/
EXTRACT_SUFX=	_tar.gz

MAINTAINER=	makoto@ki.nu
HOMEPAGE=	http://www.arrl.org/files/file/LoTW%20Instructions/
COMMENT=	Tqsl library for ARRL LoTW
#LICENSE=	See LICENSE file (ARRL)

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_LIBTOOL=	yes

# By default, DISTNAME is expected.
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

# There is a failure to find tqsllib.la; this fixed it (situation not clear).
MAKE_JOBS_SAFE=		no
# The configure script is broken and looks in explicit paths, instead
# of just trying to link.
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
