# $NetBSD: Makefile,v 1.11 2010/02/22 20:00:10 thomasklausner Exp $
#

DISTNAME=		nzbget-0.2.3
PKGREVISION=		3
CATEGORIES=		news
MASTER_SITES=		$(MASTER_SITE_SOURCEFORGE:=nzbget/)

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://sourceforge.net/projects/nzbget/
COMMENT=		Binary newsreader with NZB support

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf gmake
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	bin $(EGDIR)

EGDIR=			$(PREFIX)/share/examples/nzbget
MESSAGE_SUBST+=		EGDIR=$(EGDIR)

pre-configure:
	cd $(WRKSRC); autoconf

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/nzbget $(DESTDIR)$(PREFIX)/bin
	$(INSTALL_DATA) $(WRKSRC)/nzbget.cfg.example \
		$(DESTDIR)$(EGDIR)/nzbget.cfg.example

.include "../../converters/uulib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
