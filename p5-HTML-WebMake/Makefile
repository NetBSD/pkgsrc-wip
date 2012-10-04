# $NetBSD: Makefile,v 1.3 2012/10/04 10:45:29 asau Exp $
#

DISTNAME=	HTML-WebMake-2.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://webmake.sourceforge.net/devel/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	http://webmake.sourceforge.net/devel/
COMMENT=	WebMake is a simple web site management system

PERL5_PACKLIST=		auto/HTML/WebMake/.packlist

DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-Text-EtText-[0-9]*:../../wip/p5-Text-EtText
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-XML-Sablotron-[0-9]*:../../textproc/p5-XML-Sablotron
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size

PKG_DESTDIR_SUPPORT=	none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
