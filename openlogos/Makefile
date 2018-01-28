# $NetBSD: Makefile,v 1.8 2012/10/03 21:32:47 asau Exp $

DISTNAME=	openlogos-1.0.3
CATEGORIES=	misc
MASTER_SITES=	http://logos-os.dfki.de/release/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://logos-os.dfki.de/
COMMENT=	Openlogos is a language translation system


USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_JAVA=		yes
CONFIGURE_ARGS+=	--with-java=${PKG_JAVA_HOME}

CPPFLAGS.SunOS+=	-Du_int32_t=uint32_t -D__int32_t=int32_t -Du_int16_t=uint16_t -D__int16_t=int16_t -Dstrerror_r\(x,y,z\)=strerror\(x\)

SUBST_CLASSES+=		sysio
SUBST_STAGE.sysio=	post-patch
SUBST_FILES.sysio=	logos_libs/dbcache/CacheCompanyData.cpp \
			logos_libs/dbcache/CacheDerivedFormData.cpp \
			logos_libs/dbcache/CacheInflectionData.cpp \
			logos_libs/lgs_tran_rule_io/tran_rule_io.cpp \
			logos_libs/lgs_tran_rule_io/res_rule_io.cpp
SUBST_SED.sysio=	-f ${FILESDIR}/sysio.sed
SUBST_MESSAGE.sysio=	Do not include sys/io.h on Solaris

.include "../../devel/libltdl/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
