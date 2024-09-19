# $NetBSD$

DISTNAME=		uuid-1.6.2
PKGNAME=		p5-OSSP-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		ftp://ftp.ossp.org/pkg/lib/uuid/

MAINTAINER=		mishka@NetBSD.org
HOMEPAGE=		http://www.ossp.org/pkg/lib/uuid/
COMMENT=		OSSP uuid Perl binding
LICENSE=		mit

PERL5_CONFIGURE_DIRS=	perl
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

PERL5_PACKLIST=		auto/OSSP/uuid/.packlist

.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
