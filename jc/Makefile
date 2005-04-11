# $NetBSD: Makefile,v 1.4 2005/04/11 21:13:21 tvierling Exp $
#

DISTNAME=		jc-1.2.3
CATEGORIES=		wip lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jcvm/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jcvm.sourceforge.net/
COMMENT=		Native java compiler using gcc

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_MAKEINFO=	yes
INFO_FILES=jc.info jc.info-1 jc.info-2 jc.info-3

CONFIGURE_ARGS+=--disable-assertions

DEPENDS+=   classpath>=0.12:../../lang/classpath

SUBST_CLASSES=uname gcc
SUBST_FILES.uname=configure
SUBST_STAGE.uname=pre-configure
SUBST_SED.uname=-e 's/uname -p/uname -m/g'
SUBST_FILES.gcc=jsrc/Makefile
SUBST_STAGE.gcc=pre-install
SUBST_SED.gcc=-e 's/HOSTGCC\ =/HOSTGCC=\/usr\/bin\/gcc\ \#/g'

ONLY_FOR_PLATFORM=*-*-i386

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
