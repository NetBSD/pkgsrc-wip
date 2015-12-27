# $NetBSD$

DISTNAME=	MoarVM-2015.12
CATEGORIES=	wip perl6
MASTER_SITES=	http://www.moarvm.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.moarvm.org/
COMMENT=	Virtual machine for Rakudo Perl 6
LICENSE=	artistic-2.0

USE_TOOLS+=	perl gmake
USE_LANGUAGES=	c c++

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--has-libatomic_ops \
			--has-libffi \
			--has-libuv \
			--has-libtommath

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
