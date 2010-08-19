# $NetBSD: Makefile,v 1.2 2010/08/19 18:00:30 erinlalouve Exp $
#

PKGNAME=	seeks-0.2.4
DISTNAME=	seeks_solo_stable-0.2.4
CATEGORIES=	local
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seeks/}

MAINTAINER=	erinlalouve@free.fr
HOMEPAGE=	https://www.seeks-project.info/
COMMENT=	Decentralized metasearch engine

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=	no

DEPENDS+=       autogen-[0-9]*:../../devel/autogen
DEPENDS+=       autoconf>=2.59:../../devel/autoconf
DEPENDS+=       automake>=1.8.2:../../devel/automake

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake gmake

WRKSRC=		${WRKDIR}/seeks # More than one possibility -- please check manually.

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
