# $NetBSD: Makefile,v 1.7 2022/11/23 16:19:45 adam Exp $

DISTNAME=	SOPE-5.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Alinto/}
GITHUB_PROJECT=	sope
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inverse-inc/sope
COMMENT=	Framework for writing clever web servers driven by objects
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	objc
USE_TOOLS+=	gmake

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-gnustep --enable-debug --disable-strip

LDFLAGS+=	-L${PREFIX}/lib
MAKE_ENV+=	ADDITIONAL_LDFLAGS=${LDFLAGS:Q}

# ld: -r and -pie may not be used together
MKPIE_SUPPORTED=	no

# options.mk are not supported because gnustep-make/-base set
# PKG_OPTIONS_VAR to support the fragile option.
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"

pre-configure:
	${TEST} -e ${BUILDLINK_DIR}/lib/libmysqlclient.so || \
	${LN} -s ${BUILDLINK_DIR}/lib/mysql/libmysqlclient.so \
	${BUILDLINK_DIR}/lib/libmysqlclient.so

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
