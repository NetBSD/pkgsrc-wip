# $NetBSD: Makefile,v 1.1.1.1 2011/12/08 12:24:10 khorben Exp $

MODNAME=		php_gtk2
PECL_VERSION=		2.0.1
PECL_DISTNAME=		php-gtk-${PECL_VERSION}
CATEGORIES+=		x11
COMMENT=		PHP extension for writing GUI applications with Gtk+
MASTER_SITES=		http://gtk.php.net/do_download.php?download_file=

MAINTAINER=		khorben@defora.org
HOMEPAGE=		http://gtk.php.net/
COMMENT=		PHP extension for Gtk+ 2.0
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		awk
USE_TOOLS+=		pkg-config

BUILD_DEPENDS+=		re2c:../../devel/re2c

CONFIGURE_ARGS+=	--without-libglade

#XXX phpize needs to be run with specific arguments
phpize-module:
	@cookie=${WRKDIR}/.phpize_module_done;				\
	if [ ! -f $${cookie} ]; then					\
		cd ${WRKSRC} && 					\
		./buildconf --with-phpize=${PHPIZE} &&			\
		${TOUCH} ${TOUCH_FLAGS} $${cookie};			\
	fi

.include "../../lang/php/ext.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
