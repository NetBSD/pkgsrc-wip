# $NetBSD: Makefile,v 1.12 2012/11/25 23:32:24 othyro Exp $
#

DISTNAME=		jc-1.2.3
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jcvm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jcvm.sourceforge.net/
COMMENT=		Native java compiler using gcc


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-assertions

DEPENDS+=	classpath>=0.12:../../lang/classpath

SUBST_CLASSES+=		uname gcc
SUBST_FILES.uname=	configure
SUBST_STAGE.uname=	pre-configure
SUBST_SED.uname=	-e 's/uname -p/uname -m/g'
SUBST_FILES.gcc=	jsrc/Makefile
SUBST_STAGE.gcc=	pre-install
SUBST_SED.gcc=		-e 's/HOSTGCC\ =/HOSTGCC=\/usr\/bin\/gcc\ \#/g'

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
