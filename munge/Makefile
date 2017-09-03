# $NetBSD: Makefile,v 1.14 2016/03/05 11:29:22 jperkin Exp $

DISTNAME=	munge-0.5.11
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	http://munge.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://dun.github.io/munge/
COMMENT=	Authentication service for creating and validating credentials

USE_TOOLS=	perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--localstatedir=$(VARBASE)
INSTALLATION_DIRS+=	lib/pkgconfig

OWN_DIRS=	$(VARBASE)/lib/munge $(VARBASE)/log/munge $(VARBASE)/run/munge

RCD_SCRIPTS+=	munge

SUBST_CLASSES+=		init
SUBST_STAGE.init=	post-build
SUBST_FILES.init=	${WRKSRC}/src/etc/munge.init
SUBST_SED.init=		-e 's|USER="munge"|USER="daemon"|g'
SUBST_SED.init+=	-e 's|GROUP="munge"|GROUP="daemon"|g'

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
