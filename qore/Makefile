# $NetBSD: Makefile,v 1.3 2014/01/14 20:09:45 nros Exp $

DISTNAME=	qore-0.8.8
CATEGORIES=	lang

.include	"../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Qore programming language
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake flex bison
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

PKGCONFIG_OVERRIDE+=	qore.pc.in
CONFIGURE_ARGS+= 	--with-doxygen=no
INSTALL_TARGET=	install install-html-local

#NetBSD 6 and lower has an stdio.h that breaks this package
NOT_FOR_PLATFORM=       NetBSD-[0-6]*-*

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
