# $NetBSD: Makefile,v 1.3 2011/03/23 16:30:42 erinlalouve Exp $
#

PKGNAME=	seeks-0.3.2
DISTNAME=	seeks-0.3.2
CATEGORIES=	local
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=seeks/}

MAINTAINER=	erin.nivelet@erinlalouve.com
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

WRKSRC=		${WRKDIR}/seeks-0.3.2 

.include "../../devel/pcre/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../wip/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
