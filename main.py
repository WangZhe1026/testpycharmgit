# import torch
#
# def unet_model():
#     model = torch.hub.load('mateuszbuda/brain-segmentation-pytorch', 'unet',
#     in_channels=3, out_channels=1, init_features=32, pretrained=True)
#     return model
#
# if __name__ == '__main__':
#     model = unet_model()
#     print(model)
import torch



import torch.nn as nn

class UNet(nn.Module):
    def __init__(self, in_channels, out_channels):
        super(UNet, self).__init__()
        # Define the encoder part
        self.encoder = nn.Sequential(
            # Define encoder convolutional layers, pooling layers, etc.
            nn.Conv2d(in_channels, 64, kernel_size=3, padding=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2)
            # Add more layers as needed
        )

        # Define the decoder part
        self.decoder = nn.Sequential(
            # Define decoder convolutional layers, upsampling layers, etc.
            nn.ConvTranspose2d(64, in_channels, kernel_size=3, stride=2, padding=1, output_padding=1),
            nn.ReLU()
            # Add more layers as needed
        )

        # Define the final classifier part
        self.classifier = nn.Conv2d(64, out_channels, kernel_size=1)

    # Define the forward method
    def forward(self, x):
        # Implement the forward pass
        # Example: forward pass of the encoder, skip connections, forward pass of the decoder, etc.
        return x

# Create an instance of the UNet model
model = UNet(in_channels=3, out_channels=1)
print(model)

