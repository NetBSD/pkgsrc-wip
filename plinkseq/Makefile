# $NetBSD: Makefile,v 1.1 2012/09/13 01:47:02 outpaddling Exp $
#

DISTNAME=	plinkseq-0.08
CATEGORIES=	biology
MASTER_SITES=	http://atgu.mgh.harvard.edu/plinkseq/dist/version-0.08/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://atgu.mgh.harvard.edu/plinkseq/dist/version-0.08/
COMMENT=	C/C++ library for working with human genetic variation data
LICENSE=	gnu-gpl-v2	# Assuming same as plink.  No info on web.

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gsed

BUILD_DEPENDS+=	gsed:../../textproc/gsed

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
post-patch:
	for m in ${WRKSRC}/*/Makefile.in; do \
		gsed -i'.orig' -e 's/-ldl//g' $${m}; \
	done
.endif

.include "../../wip/protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
