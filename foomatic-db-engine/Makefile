# $NetBSD: Makefile,v 1.2 2004/06/13 18:56:25 thomasklausner Exp $

DISTNAME=	foomatic-db-engine-3.0.1
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/download/foomatic/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/
COMMENT=	Spooler independent postscript printing filter

DEPENDS+=	foomatic-filters>=3.0.1:../../wip/foomatic-filters
#DEPENDS+=	foomatic-db-[0-9]*:../../wip/foomatic-db # XXX

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

USE_GNU_TOOLS+=	make
USE_PERL5=	yes
PERL5_REQD=	5.6
REPLACE_PERL+=	makeMan makeDefaults

CPPFLAGS+=	-I${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
