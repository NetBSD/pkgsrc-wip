# $NetBSD: Makefile,v 1.4 2012/11/16 18:51:39 kristerw Exp $

MODNAME=		php_gtk2
PECL_VERSION=		2.0.1
PECL_DISTNAME=		php-gtk-${PECL_VERSION}
CATEGORIES+=		x11
COMMENT=		PHP extension for writing GUI applications with Gtk+
MASTER_SITES=		http://gtk.php.net/do_download.php?download_file=
EXTRACT_SUFX=		.tar.gz

MAINTAINER=		khorben@defora.org
HOMEPAGE=		http://gtk.php.net/
COMMENT=		PHP extension for Gtk+ 2.0
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		awk
USE_TOOLS+=		pkg-config

BUILD_DEPENDS+=		re2c-[0-9]*:../../devel/re2c

CONFIGURE_ARGS+=	--without-libglade

BROKEN=			phpize-module redefined and breaks the package framework
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
