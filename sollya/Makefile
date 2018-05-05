# $NetBSD: Makefile,v 1.1 2015/05/20 22:33:29 alnsn Exp $

DISTNAME=	sollya-6.0
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/36270/

MAINTAINER=	alnsn@yandex.ru
HOMEPAGE=	https://gforge.inria.fr/projects/sollya/
COMMENT=	Environment and library for safe floating-point code development
LICENSE=	cecil-1.0 AND gnu-lgpl-v3

# XXX Form is optional, check the licence terms if distribution is allowed
RESTRICTED=		Optional form on download page
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/fplll/buildlink3.mk"
.include "../../wip/mpfi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
