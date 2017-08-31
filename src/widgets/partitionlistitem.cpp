#include "partitionlistitem.h"

#include <QIcon>
#include <QDebug>

PartitionListItem::PartitionListItem(DPartInfo info, QWidget *parent)
    : UtilityListDeviceItem(parent)
    , m_info(info)
{
    setTitle(info.mountPoint().isEmpty() ? info.partLabel() : info.mountPoint());
    setMessage(info.name());
    setSize(info.usedSize(), info.totalSize());

    QString icon_name;

    if (info.isRemoveable()) {
        if (info.transport().isEmpty())
            icon_name = "drive-removable-media";
        else
            icon_name = "drive-removable-media-" + info.transport();
    } else {
        if (info.transport().isEmpty())
            icon_name = "drive-harddisk";
        else
            icon_name = "drive-harddisk-" + info.transport();
    }

    setIcon(QIcon::fromTheme(icon_name), QSize(48, 48));
}

DPartInfo PartitionListItem::info() const
{
    return m_info;
}
