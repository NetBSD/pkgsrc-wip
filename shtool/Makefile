# $NetBSD$

DISTNAME=	shtool-2.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=shtool/}

MAINTAINER=	shozp@directbox.com
HOMEPAGE=	https://www.gnu.org/software/shtool/
COMMENT=	Small but very stable and portable shell scripts into a single shell tool
LICENSE=	gnu-gpl-v2

DEPENDS+=	perl5-[0-9]*:../../lang/perl5

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl gmake

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
